using UnityEngine;
using TMPro;

public class GameLogic : MonoBehaviour
{   
    public GameObject truck;
    public TMP_Text scoreText;
    public TMP_Text timerText;
    public TMP_Text gameOverText;
    private int score = 0;
    public float maxTime = 60;

    private bool gameOver = false;

    //a public function is accessible from other Game Objects
    public void incrementScore () {
        score++;
        scoreText.text = "score: " + score.ToString();
    }

    //timer function
    void Update()
    {
        if (!gameOver) {
            maxTime -= Time.deltaTime;
            timerText.text = "Time: " + Mathf.CeilToInt(maxTime).ToString();
            if (maxTime <= 0 && !gameOver)
            {
                //game over
                gameOver = true;
                gameOverText.gameObject.SetActive(true);
            }
        }
    }

    //start over function
    public void startOver() {
        score = 0;
        //notice how we convert score to a string!
        scoreText.text = "score: " + score.ToString();
        maxTime = 60;
        gameOver = false;
        gameOverText.gameObject.SetActive(false);
        //set the rigid body physics to zero
        //sphere.GetComponent<Rigidbody>().velocity = Vector3.zero;
        truck.transform.position = new Vector3(5f, 0.0f, 10f);
        //for each child of sphere (the trash objects) re-enable the collider and set the parent to null
        for (int i = truck.transform.childCount - 1; i >= 0; i--)
            {
                Transform child = truck.transform.GetChild(i);
                child.GetComponent<Collider>().enabled = true;
                child.parent = null;
                child.transform.position = new Vector3(Random.Range(-10, 10), 0f, Random.Range(-10, 10));
            }
    }
}