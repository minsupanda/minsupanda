using System;
using System.Xml;
using System.Reflection;
using System.Collections.Generic;
using UnityEngine;

public class XML<T> where T : new()
{
    /// <summary>
    /// Resources 폴더에서 xml 파일을 찾는다.
    /// </summary>
    public static List<T> Read(string name)
    {
        if (string.IsNullOrEmpty(name)) throw new ArgumentNullException("name");

        // name에서 확장자를 제외.
        name = System.IO.Path.GetFileNameWithoutExtension(name);
        var xmlText = Resources.Load<TextAsset>(name);
        if (!xmlText) throw new Exception(string.Format("Not Find TextAsset : {0}", name));

        var xmlDoc = new XmlDocument();
        xmlDoc.LoadXml(xmlText.text); // text파일을 xml 데이터 형태로 변환.
        var root = xmlDoc.DocumentElement;
        List<T> dataList = new List<T>();
        foreach (XmlElement node in root.ChildNodes)
        {
            // Reflection을 이용하여,
            T data = new T();
            var type = data.GetType();   //  T의 데이터형(Type)과,
            var fields = type.GetFields(); // 변수(Field)들을 찾는다.
            foreach (var field in fields)
            {
                // xml에서 변수 명과 같은 Attribute를 찾아 값을 가져 온다.
                var strValue = node.GetAttribute(field.Name);
                if (null != strValue) // 빈 문자열이 있을 수 깄기 때문에 null 확인만 한다.
                {
                    object value = strValue;
                    if (int.TryParse(strValue, out int i)) value = i;
                    else if (float.TryParse(strValue, out float f)) value = f;
                    else if (double.TryParse(strValue, out double d)) value = d;

                    // 해당 field에 맞는 값으로 데이터를 입력.
                    field.SetValue(data, value);
                }
            }
            // List에 데이터 추가.
            dataList.Add(data);
        }

        return dataList;
    }

    /// <summary>
    /// Assets/Resources/...폴더에 name으로 xml 파일 생서.
    /// </summary>
    public static void Write(string name, List<T> dataList)
    {
        if (string.IsNullOrEmpty(name)) throw new ArgumentNullException("name");
        if(null == dataList || 1 > dataList.Count) throw new ArgumentNullException("dataList");

        var xmlDoc = new XmlDocument();
        var root = xmlDoc.CreateElement("root"); // xml 데이터의 root 생성.
        xmlDoc.AppendChild(root);                    // xml 데이터에 root 추가.

        var type = typeof(T); // Reflection을 이용하여 데이터를 구하기 위해 Type을 구한다.
        foreach (var data in dataList)
        {
            // T의 데이터형을 이름으로 하는 Element를 생성.
            var node = xmlDoc.CreateElement(type.Name);

            var fields = type.GetFields();
            foreach (var field in fields)
            {
                // 변수명을 이름으로 하는 Attribute를 생성.
                var attr = xmlDoc.CreateAttribute(field.Name);
                // 변수가 지니고 있는 값을 문자열형태로 변환하여 Attribute에 삽입.
                attr.Value = field.GetValue(data).ToString();
                // Element에 Attribute 추가.
                node.Attributes.Append(attr);
            }
            // root에 Element 추가.
            root.AppendChild(node);
        }

        // 확장자가 있으면 ".xml"로 변경, 없다면 추가.
        name = System.IO.Path.ChangeExtension(name, ".xml");
        // Application.dataPath : Assets 폴더까지의 경로.
        // .../Assets/Resources/name.xml
        var path = string.Format(@"{0}/Resources/{1}", Application.dataPath, name);
        // 파일명을 제외한 최하위 폴더까지의 경로만을 구한다.
        var directoryPath = System.IO.Path.GetDirectoryName(path);
        // Assets 폴더의 바로 하위에 Resources 폴더가 없다면 생성.
        if (!System.IO.Directory.Exists(directoryPath)) System.IO.Directory.CreateDirectory(directoryPath);

        // 해당 프로젝트의 Resources/...폴더에 xml 파일 생성.
        xmlDoc.Save(path);
    }
}
