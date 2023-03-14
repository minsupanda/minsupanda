using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using DK.FSM;

[CreateAssetMenu(fileName = "VisitBankAndDepositGold", menuName = "FSM/VisitBankAndDepositGold", order = 2)]
public class VisitBankAndDepositGold : StateBase<Miner>
{
	[SerializeField] StateBase<Miner> satisfiedChangeState;
	[SerializeField] StateBase<Miner> notSatisfiedChangeState;

	public override void Enter(Miner agent)
    {
        Debug.LogWarning("System : (" + agent.Name + ") �������� �̵�.");
    }

    public override void Excute(Miner agent)
	{
		agent.AddToWealth();

		Debug.Log("System : (" + agent.Name + ") �ݵ��� ����.\n ���� �ܱ� : " + agent.Wealth);

		if (agent.Satisfied)
		{
			Debug.LogError(agent.Name + "\"���! ���� ���� ���ڴ�.������ ���ư���.\"");
			agent.ChangeState(satisfiedChangeState);
		}
		else agent.ChangeState(notSatisfiedChangeState);
	}

    public override void Exit(Miner agent)
    {
        Debug.LogWarning("System : (" + agent.Name + ") ������ ������.");
    }
}
