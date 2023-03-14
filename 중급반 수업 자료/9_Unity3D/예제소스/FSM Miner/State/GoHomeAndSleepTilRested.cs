using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using DK.FSM;

[CreateAssetMenu(fileName = "GoHomeAndSleepTilRested", menuName = "FSM/GoHomeAndSleepTilRested", order = 0)]
public class GoHomeAndSleepTilRested : StateBase<Miner>
{
    [SerializeField] StateBase<Miner> recoveryChangeState;

    public override void Enter(Miner agent)
    {
        Debug.LogWarning("System : (" + agent.Name + ") ������ ����.");
    }

    public override void Excute(Miner agent)
    {
        if (!agent.Fatigued)
        {
            Debug.LogError(agent.Name + "\"������ �þ����� ���! �ٽ� ���� ĳ�� ���߰ڱ�.\"");
            agent.ChangeState(recoveryChangeState);
        }
        else
        {
            agent.DecreaseFatigue();
            Debug.Log("System : (" + agent.Name + ") ...zZ");
        }
    }

    public override void Exit(Miner agent)
    {
        Debug.LogWarning("System : (" + agent.Name + ") ���� ������.");
    }
}
