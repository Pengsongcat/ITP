using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;
using System;
using Newtonsoft.Json;
using TMPro;

public class FalComfyUIDownloader : MonoBehaviour
{
    
    
    public TMP_InputField promptText;
    [SerializeField] string ENDPOINT_URL = "https://fal.run/comfy/kuripl/new-test";
    [SerializeField] string KEY;
    [SerializeField] bool enableLogs = true;
    [SerializeField] public RequestParameters requestParameters;
    [SerializeField] List<Texture2D> outputImages = new List<Texture2D>();

    [Serializable]
    public class RequestParameters
    {
        public string prompt = "";
        //public string image_url = "https://raw.githubusercontent.com/comfyanonymous/ComfyUI/master/input/example.png";
        //public string lora_url = "https://huggingface.co/ProGamerGov/360-Diffusion-LoRA-sd-v1-5/resolve/main/360Diffusion_v1.safetensors?download=true";
        //public int ksampler_seed = 1000;
        //public int emptylatentimage_width = 512;
        //public int emptylatentimage_height = 512;
    }
    // Start is called before the first frame update
    public void updatePrompt()
    {
        requestParameters.prompt = promptText.text;
        ApiRequest();
    }

    public void ApiRequest()
    {
        Debug.Log("New Request made to the API with prompt: " + requestParameters.prompt);
        StartCoroutine(SendRequestToAPI());
    }

    private IEnumerator SendRequestToAPI()
    {
        UnityWebRequest www = new UnityWebRequest(ENDPOINT_URL, "POST");
        www.SetRequestHeader("Authorization", "Basic " + KEY);
        www.SetRequestHeader("Content-Type", "application/json");

        string encodedFullInputObjects = JsonUtility.ToJson(requestParameters);
        www.uploadHandler = new UploadHandlerRaw(System.Text.Encoding.UTF8.GetBytes(encodedFullInputObjects));
        www.downloadHandler = new DownloadHandlerBuffer();

        if (enableLogs) Debug.Log("API Request sent with data: " + encodedFullInputObjects);

        yield return www.SendWebRequest();

        if (www.result == UnityWebRequest.Result.ConnectionError || www.result == UnityWebRequest.Result.ProtocolError)
        {
            Debug.LogError("API Connection Error: " + www.error);
        }

        else
        {
            string jsonResponse = www.downloadHandler.text;
            RootObject root = JsonUtility.FromJson<RootObject>(jsonResponse);
            string url = root.images[0].url;
            Debug.Log(url);
            StartCoroutine(DownloadImage(url));
        }
    }

    private IEnumerator DownloadImage(string url)
    {
        if (enableLogs) Debug.Log("Starting download for image URL: " + url);
        UnityWebRequest request = UnityWebRequestTexture.GetTexture(url);
        yield return request.SendWebRequest();

        if (request.result == UnityWebRequest.Result.ConnectionError || request.result == UnityWebRequest.Result.ProtocolError)
        {
            Debug.LogError("Error downloading image: " + request.error);
        }
        else
        {
            Texture2D outputImage = DownloadHandlerTexture.GetContent(request);
            outputImages.Add(outputImage);
            //for each gameobject tagged with "point" in the scene, apply the downloaded image
            GameObject[] pushers = GameObject.FindGameObjectsWithTag("textured");
            foreach (GameObject pusher in pushers) {
                pusher.GetComponent<Renderer>().material.mainTexture = outputImage;
            }
            
            if (enableLogs) Debug.Log("Image downloaded and applied.");
        }
    }

    [System.Serializable]
    public class Image
    {
        public string url;
        public int width;
        public int height;
        public string content_type;
    }

    [System.Serializable]
    public class RootObject
    {
        public Image[] images;
    }
    [Serializable]
    public class OutputImages
    {
        public List<ImageData> images;
    }

    [Serializable]
    public class ImageData
    {
        public string filename;
        public string subfolder;
        public string type;
        public string url;
    }
}
