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
        Debug.LogWarning("System : (" + agent.Name + ") 은행으로 이동.");
    }

    public override void Excute(Miner agent)
	{
		agent.AddToWealth();

		Debug.Log("System : (" + agent.Name + ") 금덩이 저금.\n 현재 잔금 : " + agent.Wealth);

		if (agent.Satisfied)
		{
			Debug.LogError(agent.Name + "\"우와! 이제 나는 부자다.집으로 돌아가지.\"");
			agent.ChangeState(satisfiedChangeState);
		}
		else agent.ChangeState(notSatisfiedChangeState);
	}

    public override void Exit(Miner agent)
    {
        Debug.LogWarning("System : (" + agent.Name + ") 은행을 떠난다.");
    }
}
