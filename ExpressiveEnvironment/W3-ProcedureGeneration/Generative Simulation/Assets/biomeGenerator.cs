using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class biomeGenerator : MonoBehaviour
{
    public GameObject flower;
    [Header("Voxel Settings")]
    public GameObject voxel;
    public int mapSize = 10;
    public float spacing = 1.0f;

    public float depth = 3.0f;
    
    // Start is called before the first frame update
    void Start()
    {
        //loop through all the positions in our map
        //notice that we have a nested loop, one inside the other in order to create z coordinates for each x coordinate
        for (int x = -mapSize; x < mapSize; x++)
        {
            for (int z = -mapSize; z < mapSize; z++)
            {
                //grab a perlin noise value between 0 and 1 at our current position in the loop
                //scale the x and z values by 0.1 to make the perlin noise more gradual from point to point, otherwise our noise won't be very smooth
                float y = Mathf.PerlinNoise(x * 1.0f, z * 1.0f) * depth;
                Debug.Log(y);
                Vector3 pos = new Vector3(x * spacing, y, z * spacing);
                var newVoxel = Instantiate(voxel, pos, Quaternion.identity);
                newVoxel.transform.parent = gameObject.transform;
                //uncomment the Debug.log(y) line to see the perlin noise values in the console, this is useful for determining what values to use for your thresholds
                //Debug.Log(y);
                if (y > 1 && Random.Range(0, 100) < 50)
                {
                    var pos2 = new Vector3(x * spacing, y + 0.5f, z * spacing);
                    var newAgent = Instantiate(flower, pos2, Quaternion.identity);
                    newAgent.transform.parent = gameObject.transform;
                }
            }
        }
    }

    

}
