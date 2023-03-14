using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using DK.FSM;

public enum THRESHOLD
{
    COMFORT_LEVEL = 5,  // 안락함을 느끼는 금덩이의 양.
    MAX_NUGGETS = 3,    // 최대 소지금.
    THIRST_LEVEL = 5,       // 갈증 한계.
    TIREDNESS = 5           // 피로 한계.
}

public class Miner : MonoBehaviour
{
    StateMachine<Miner> stateMachine;

    [SerializeField] StateBase<Miner> initState;
    [SerializeField] string agentName = "Bob";

    int goldCarried;      // 광부가 광산에서 캔 금덩이의 양.
    int moneyInBank;   // 저축 금액.
    int thirst;              // 갈증도.
    int fatigue;		      // 피로도.

    public string Name { get => agentName; }
    public int GoldCarried { get => goldCarried; }
    public int Wealth { get => moneyInBank; set => moneyInBank = value; }
    public bool Thirsty { get => ((int)THRESHOLD.THIRST_LEVEL < thirst); }
    public bool Fatigued { get => ((int)THRESHOLD.TIREDNESS < fatigue); }
    public bool PocketsFull { get => ((int)THRESHOLD.MAX_NUGGETS <= GoldCarried); }
    public bool Satisfied { get => ((int)THRESHOLD.COMFORT_LEVEL <= Wealth); }

    public void DecreaseFatigue() { fatigue--; }
    public void IncreaseFatigue() { fatigue++; }
    public void BuyAndDrinkAWhiskey() { thirst = 0; moneyInBank -= 2; }
    public void AddToGoldCarried(int value) { goldCarried = Mathf.Max(goldCarried + value, 0); }
    public void AddToWealth() { moneyInBank = Mathf.Max(moneyInBank + GoldCarried, 0); goldCarried = 0; }

    public void ChangeState(StateBase<Miner> state)
    {
        stateMachine.ChangeState(state);
    }

    private void Start()
    {
        stateMachine = new StateMachine<Miner>(this);
        stateMachine.SetCurrentState(initState);

        StartCoroutine(Processing());
    }

    IEnumerator Processing()
    {
        while (true)
        {
            thirst++;
            stateMachine.Update();
            yield return new WaitForSeconds(1);
        }
    }
}
