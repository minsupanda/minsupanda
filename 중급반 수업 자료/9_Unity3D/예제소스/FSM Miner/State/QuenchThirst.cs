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
        Debug.LogWarning("System : (" + agent.Name + ") �������� ����.");
        Debug.LogError(agent.Name + "\"���� ������!\"");
    }

    public override void Excute(Miner agent)
	{
		// ������ �ִٸ�,
		if (agent.Thirsty)
		{
			agent.BuyAndDrinkAWhiskey();

			Debug.LogError("System : (" + agent.Name + ") ���� ���Ŵ�.");
			Debug.Log("System : (" + agent.Name + ") ���� �ܱ� : " + agent.Wealth);
		}
		else Debug.Log("Error! Error! Error!");

		agent.ChangeState(recoveryChangeState);
	}

    public override void Exit(Miner agent)
    {
        Debug.LogWarning("System : (" + agent.Name + ") ������ ������.");
    }
}
