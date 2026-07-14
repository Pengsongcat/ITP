using UnityEngine;

public class Drive : MonoBehaviour
{
    public float forceAmount = 10; // Adjust this to control the force applied to the ball
    public float turnSpeed = 5; // Adjust this to control the speed at which the ball turns
    //center point of the ball
    public GameObject pointer;
    //interface with the game logic (the mechanism that keeps track of the score)
    public GameObject GameLogicObject;
    //create a reference to the rigidbody component, which we will use to apply forces to the ball
    private Rigidbody rb;
    
    private void Start()
    {
        rb = GetComponent<Rigidbody>();
    }

    private void Update()
    {
        //make the pointer follow the ball
        // pointer position == truck position
        pointer.transform.position = new Vector3(transform.position.x, transform.position.y, transform.position.z);
        // Apply forward force when the W key is pressed
        if (Input.GetKey(KeyCode.W))
        {
            // Move forward relative to the ball's current direction
            Vector3 forwardForce = -pointer.transform.forward * forceAmount;
            rb.AddForce(forwardForce);   
        }

        if (Input.GetKey(KeyCode.S))
        {
            // Move forward relative to the ball's current direction
            Vector3 forwardForce = pointer.transform.forward * forceAmount;
            rb.AddForce(forwardForce);   
        }

        // Rotate left when the A key is pressed
        if (Input.GetKey(KeyCode.A))
        {
            //rotate the pointer around the ball
            pointer.transform.Rotate(Vector3.up, turnSpeed);
        }

        // Rotate right when the D key is pressed
        if (Input.GetKey(KeyCode.D))
        {
            pointer.transform.Rotate(Vector3.up, -turnSpeed);
        }
    }

    private void OnTriggerEnter(Collider other)
    {
        //filters out collisions with the ground and non-point scoring objects
        if (other.CompareTag("trash"))
        {
            //make other object a child of the ball to control its transform
            other.transform.parent = transform;
            //play sound on other game object
            other.GetComponent<AudioSource>().Play();
            //disable the collider so that it doesn't effect the roll of the ball
            other.enabled = false;
            //increase the score
            GameLogicObject.GetComponent<GameLogic>().incrementScore();
        }
    }
}
