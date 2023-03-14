using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace DK
{
    namespace FSM
    {
        public sealed class StateMachine<T> where T : MonoBehaviour
        {
            private T m_Agent;
            private StateBase<T> m_currState = null;
            private StateBase<T> m_prevState = null;
            private StateMachine() { }
            public StateMachine(T agent)
            {
                m_Agent = agent;
            }

            public StateBase<T> CurrentState { get { return m_currState; } }
            public StateBase<T> PreviousState { get { return m_prevState; } }
            public void SetCurrentState(StateBase<T> state) { if (null != state) m_currState = state; }
            public void SetPreviousState(StateBase<T> state) { if (null != state) m_prevState = state; }
            public void Update() { if (null != m_currState && m_Agent) m_currState.Excute(m_Agent); }
            public void ChangeState(StateBase<T> newState)
            {
                if (null == newState) return;
                m_prevState = m_currState;
                m_currState.Exit(m_Agent);
                m_currState = newState;
                m_currState.Enter(m_Agent);
            }
            public void ChageByPreviousState()
            {
                ChangeState(m_prevState);
            }
        }
    }
}