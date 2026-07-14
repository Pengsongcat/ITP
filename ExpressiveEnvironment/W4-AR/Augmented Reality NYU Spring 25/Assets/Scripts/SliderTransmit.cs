using UnityEngine;
/* Copyright (c) 2020 ExT (V.Sigalkin) */

using UnityEngine;

namespace extOSC.Examples
{
	public class SliderTransmit : MonoBehaviour
	{
		#region Public Vars
        
		public string Address = "/example/1";

		[Header("OSC Settings")]
		public OSCTransmitter Transmitter;

		#endregion

		#region Unity Methods

        //on slider change
        public void OnSliderChange(float value)
        {
            var message = new OSCMessage(Address);
            message.AddValue(OSCValue.Float(value));
            Transmitter.Send(message);
            Debug.Log("slider value: " + value);
        }

		public void OnNewSeed()
        {
            var message = new OSCMessage(Address);
            message.AddValue(OSCValue.Float(1));
            Transmitter.Send(message);
            
        }

        
		#endregion
	}
}
