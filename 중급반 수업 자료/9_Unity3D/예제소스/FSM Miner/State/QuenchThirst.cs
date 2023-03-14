using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using DK.FSM;

[CreateAssetMenu(fileName = "QuenchThirst", menuName = "FSM/QuenchThirst", order = 3)]
public class QuenchThirst : StateBase<Miner>
{
	[SerializeField] StateBase<Miner> recoveryChangeState;

	public override void Enter(Miner agent)
    {
        Debug.LogWarning("System : (" + agent.Name + ") 술집으로 들어간다.");
        Debug.LogError(agent.Name + "\"목이 마르군!\"");
    }

    public override void Excute(Miner agent)
	{
		// 갈증이 있다면,
		if (agent.Thirsty)
		{
			agent.BuyAndDrinkAWhiskey();

			Debug.LogError("System : (" + agent.Name + ") 술을 마신다.");
			Debug.Log("System : (" + agent.Name + ") 현재 잔금 : " + agent.Wealth);
		}
		else Debug.Log("Error! Error! Error!");

		agent.ChangeState(recoveryChangeState);
	}

    public override void Exit(Miner agent)
    {
        Debug.LogWarning("System : (" + agent.Name + ") 술집을 떠난다.");
    }
}
