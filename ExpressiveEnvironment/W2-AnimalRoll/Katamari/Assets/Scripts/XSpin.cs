using UnityEngine;

public class XSpin : MonoBehaviour
{
    public float spinSpeed = 10f;
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        transform.Rotate(spinSpeed * Time.deltaTime, 0, 0);
    }
}
