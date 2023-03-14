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
        Debug.LogWarning("System : (" + agent.Name + ") 집으로 들어간다.");
    }

    public override void Excute(Miner agent)
    {
        if (!agent.Fatigued)
        {
            Debug.LogError(agent.Name + "\"낮잠을 늘어지게 잤네! 다시 금을 캐러 가야겠군.\"");
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
        Debug.LogWarning("System : (" + agent.Name + ") 집을 떠난다.");
    }
}
