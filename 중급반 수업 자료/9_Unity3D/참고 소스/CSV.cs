using System.Collections.Generic;
using System.Text.RegularExpressions;
using UnityEngine;

public class CSV
{
    /// <summary>
    /// 대화 등을 표기하는 "따옴표 안에, 쉼포가 있을 수 있으니, 그 조건을 제외"하고 쉼표 단위로 나눈다.
    /// </summary>
    static string SPLIT_RE = @",(?=(?:[^""]*""[^""]*"")*(?![^""]*""))";
    /// <summary>
    /// 줄 바꿈의 정규식 \r or \n or \r\n or \n\r
    /// </summary>
    static string LINE_SPLIT_RE = @"\r\n|\n\r|\n|\r";
    /// <summary>
    /// trim은 공백 제거에 사용 되는데 조건을 쓰면 공백 대신 해당 조건을 제거한다.
    /// </summary>
    static char[] TRIM_CHARS = { ' ' };

    /// <summary>
    /// 반드시 file은 Resources 폴더에 위치해야만 한다.
    /// </summary>
    public static List<Dictionary<string, string>> Read(string name)
    {
        if (string.IsNullOrEmpty(name)) throw new System.ArgumentNullException("name");

        // name에서 확장자를 제외.
        name = System.IO.Path.GetFileNameWithoutExtension(name);
        TextAsset data = Resources.Load<TextAsset>(name);
        if (!data) throw new System.Exception(string.Format("Not Find TextAsset : {0}", name));

        // 숫자를 사용할 것이 아니라면 boxing, unboxing이 발생하는 object 대신 string으로 그대로 이용하는 것이 좋다.
        var list = new List<Dictionary<string, string>>();
        // 줄 단위로 text 파일을 나눈다.
        var lines = Regex.Split(data.text, LINE_SPLIT_RE);
        // 첫 줄은 분류이기 때문에 2이상 이어야 한다.
        if (lines.Length <= 1) return list;

        // 분류를 쉼표(,) 단위로 나눈다.
        var header = Regex.Split(lines[0], SPLIT_RE);
        // 데이터의 시작 index는 1.
        for (var i = 1; i < lines.Length; i++)
        {
            // 데이터를 쉼표(,) 단위로 나눈다.
            var values = Regex.Split(lines[i], SPLIT_RE);
            // 해당 라인에 데이터가 하나도 없다면 건너뛴다.
            if (values.Length == 0 || values[0] == "") continue;

            var entry = new Dictionary<string, string>();
            // 분류보다 데이터가 적거나 많을 경우를 대비하여 최소한의 루프만을 실행.
            var count = Mathf.Min(header.Length, values.Length);
            for (var j = 0; j < count; j++)
            {
                string value = values[j];
                // 문자열의 시작과 끝에 있는 TRIM_CHARS를 제거.
                value = value.TrimStart(TRIM_CHARS).TrimEnd(TRIM_CHARS);//.Replace("\\", "");
                /*object finalValue = value;
                int n;
                float f;
                if (int.TryParse(value, out n)) finalValue = n;
                else if (float.TryParse(value, out f)) finalValue = f;*/
                value = value.Replace("<br>", "\n"); // 개행문자가 <br>일 경우 \n로 변경.
                value = value.Replace("<c>", ","); // 쉼표가 <c>일 경우 ","로 변경.
                entry[header[j]] = value; // 분류에 정리한 데이터 추가.
            }

            // 분류 별로 정리된 데이터 Dictionary를 List에 추가.
            list.Add(entry);
        }
        return list;
    }
}
