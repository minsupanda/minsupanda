using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace DK
{
    public class Curve
    {
        private List<Vector3> path = new List<Vector3>();

        private Vector3 start = Vector3.zero;
        private Vector3 initVelocity = Vector3.zero;
        private float gravity = 0;
        private float timeToTarget = 0;

        public Vector3 InitVelocity { get { return initVelocity; } }
        public float TimeToTarget { get { return timeToTarget; } }

        public void CalculateLaunch(Vector3 start, Vector3 end, float h, float gravity = -9.81f)
        {
            this.start = start;
            this.gravity = gravity;

            initVelocity = Vector3.zero;
            timeToTarget = 0;

            float displacementY = end.y - start.y;
            Vector3 displacementXZ = new Vector3(end.x - start.x, 0, end.z - start.z);

            float time = Mathf.Sqrt(-2 * h / gravity) + Mathf.Sqrt(2 * (displacementY - h) / gravity);
            if (float.IsNaN(time)) return;

            Vector3 velocityY = Vector3.up * Mathf.Sqrt(-2 * h * gravity);
            Vector3 velocityXZ = displacementXZ / time;

            initVelocity = velocityXZ + velocityY * -Mathf.Sign(gravity);
            timeToTarget = time;
        }

        public Vector3[] GetPath(int resolution = 30)
        {
            path.Clear();
            if (!initVelocity.Equals(Vector3.zero))
            {
                path.Add(start);
                for (int i = 0; resolution >= i; i++)
                {
                    float simulationTime = i / (float)resolution * TimeToTarget;
                    Vector3 displacement = InitVelocity * simulationTime + Vector3.up * gravity * simulationTime * simulationTime * 0.5f;
                    Vector3 point = start + displacement;
                    path.Add(point);
                }
            }
            return path.ToArray();
        }
    }
}