using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace DK
{
    namespace FSM
    {
        //[CreateAssetMenu(fileName = "BaseState", menuName = "FSM/State", order = 0)]
        // order : 목록 순서.
        public abstract class StateBase<T> : ScriptableObject where T : class
        {
            public abstract void Enter(T agent);

            public abstract void Excute(T agent);

            public abstract void Exit(T agent);
        }
    }
}