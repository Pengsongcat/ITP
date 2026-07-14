using UnityEngine;

public class ZSpin : MonoBehaviour
{
    public float spinSpeed = 10f;
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        //rotate the object around the Y axis
        transform.Rotate(0, 0, spinSpeed * Time.deltaTime);
    }
}
