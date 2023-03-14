using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UIScreenSpaceCameraSetPos : MonoBehaviour
{
    public Transform target;
    public Transform checker;
    public RectTransform canvas;

    void Update()
    {
        var screenPos = Camera.main.WorldToScreenPoint( target.position);
        RectTransformUtility.ScreenPointToLocalPointInRectangle(canvas, screenPos, Camera.main, out Vector2 localPos);
        checker.localPosition = localPos;
    }
}
