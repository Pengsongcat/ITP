/* Copyright (c) 2020 ExT (V.Sigalkin) */

using UnityEngine;

namespace extOSC.Examples
{
	public class ReceiveOSC : MonoBehaviour
	{
		#region Public Vars

		public string Address = "/example/1";

		[Header("OSC Settings")]
		public OSCReceiver Receiver;

		#endregion

		#region Unity Methods

		protected virtual void Start()
		{
			Receiver.Bind(Address, ReceivedMessage);
		}

		#endregion

		#region Private Methods

		private void ReceivedMessage(OSCMessage message)
		{
            //check here for documentation on how to get a Float value from the message
            //https://github.com/Iam1337/extOSC?tab=readme-ov-file#receive-oscmessage
			Debug.Log(message.Values[0].FloatValue);
            var value = message.Values[0].FloatValue;
            //use message value to change material Green value
            this.gameObject.GetComponent<Renderer>().material.color = new Color(1f, value , 1f);
            
            
		}

		#endregion
	}
}