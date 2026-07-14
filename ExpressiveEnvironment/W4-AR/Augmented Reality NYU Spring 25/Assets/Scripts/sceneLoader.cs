using UnityEngine;
using System.Collections;
using UnityEngine.SceneManagement;

public class sceneLoader : MonoBehaviour
{
    public float timeBeforeSceneChange = 10.0f;
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        StartCoroutine(LoadSceneAfterDelay());
    }

    private IEnumerator LoadSceneAfterDelay()
    {
        yield return new WaitForSeconds(timeBeforeSceneChange);
        SceneManager.LoadScene("Scene2");
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
