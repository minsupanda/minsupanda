using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using DK.FSM;

[CreateAssetMenu(fileName = "EnterMineAndDigForNugget", menuName = "FSM/EnterMineAndDigForNugget", order = 1)]
public class EnterMineAndDigForNugget : StateBase<Miner>
{
    [SerializeField] StateBase<Miner> pocketFullChangeState;
    [SerializeField] StateBase<Miner> ThirstyChangeState;

    public override void Enter(Miner agent)
    {
        Debug.LogWarning("System : (" + agent.Name + ") 광산으로 걸어간다.");
    }

    public override void Excute(Miner agent)
    {
        agent.AddToGoldCarried(1);
        agent.IncreaseFatigue();

        Debug.Log("System : (" + agent.Name + ") 금덩이 1개를 채굴.");
        if (agent.PocketsFull) agent.ChangeState(pocketFullChangeState);
        else if(agent.Thirsty) agent.ChangeState(ThirstyChangeState);
    }

    public override void Exit(Miner agent)
    {
        Debug.LogWarning("System : (" + agent.Name + ") 금덩이 " + agent.GoldCarried + "개를 가지고 광산을 떠난다.");
    }
}
