using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using DK;

public class CurveDrawTest : MonoBehaviour
{
    public Transform target;
    public float gravity = -18;
    public float height = 1;

    private Curve curve = new Curve();

    private void Update()
    {
        if (target)
        {
            curve.CalculateLaunch(transform.position, target.position, height, gravity);
            DrawPath(curve.GetPath());
        }
    }

    void DrawPath(Vector3[] path)
    {
        for (int i = 1; path.Length > i; i++)
        {
            Debug.DrawLine(path[i - 1], path[i], Color.green);
        }
    }
}
