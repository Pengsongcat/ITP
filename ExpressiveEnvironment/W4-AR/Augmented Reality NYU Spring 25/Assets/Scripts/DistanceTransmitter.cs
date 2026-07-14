/* Copyright (c) 2020 ExT (V.Sigalkin) */

using UnityEngine;

namespace extOSC.Examples
{
	public class DistanceTransmitter : MonoBehaviour
	{
		#region Public Vars
        public GameObject otherObject;
		public string Address = "/example/1";

		[Header("OSC Settings")]
		public OSCTransmitter Transmitter;

		#endregion

		#region Unity Methods

		protected virtual void Update()
		{
            if (otherObject.GetComponent<MeshRenderer>().enabled == true && this.gameObject.GetComponent<MeshRenderer>().enabled == true){
                float d = Vector3.Distance(transform.position, otherObject.transform.position);
                var message = new OSCMessage(Address);
                message.AddValue(OSCValue.Float(d));
                Transmitter.Send(message);
                Debug.Log("Distance: " + d);
            }
		}
		#endregion
	}
}
