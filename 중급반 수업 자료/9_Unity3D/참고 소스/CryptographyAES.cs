using System;
using System.IO;
using System.Text;
using System.Security.Cryptography;

public class CryptographyAES
{
    public static string Encript128(string originalText, string key)
    {
        return Encript(originalText, key, 128);
    }
    public static string Decrypt128(string encryptText, string key)
    {
        return Decrypt(encryptText, key, 128);
    }
    public static string Encript192(string originalText, string key)
    {
        return Encript(originalText, key, 192);
    }
    public static string Decrypt192(string encryptText, string key)
    {
        return Decrypt(encryptText, key, 192);
    }
    public static string Encript256(string originalText, string key)
    {
        return Encript(originalText, key, 256);
    }
    public static string Decrypt256(string encryptText, string key)
    {
        return Decrypt(encryptText, key, 256);
    }

    private static string Encript(string originalText, string key, int size)
    {
        // 예외 처리.
        if (!( (128 == size) || (192 == size) || (256 == size) )) throw new Exception("wrong size");
        if (string.IsNullOrEmpty(originalText)) throw new ArgumentNullException("originalText");
        if (string.IsNullOrEmpty(key)) throw new ArgumentNullException("key");

        string encryptedText = string.Empty;
        using (var rijAlg = new RijndaelManaged()) // using에 작성을 하면 안정적으로 생성하여 Clear 해준다.
        {
            int byteSize = (int)(size * 0.125f);
            byte[] pwBytes = Encoding.UTF8.GetBytes(key);               // key를 byte로 변환.
            byte[] keyBytes = new byte[byteSize];                           // AES128 : 16bit, AES192 : 24bit, AES256 : 32bit를 사용.
            var len = Math.Min(pwBytes.Length, keyBytes.Length);     // 길이가 더 길 경우 길이를 제한한다.
            Array.Copy(pwBytes, keyBytes, len);                              // 실제 사용할 keyBytes로 데이터를 복사.

            rijAlg.Mode = CipherMode.CBC;         // CBC 권장.
            rijAlg.Padding = PaddingMode.PKCS7; // 대표적으로 PKCS7 사용.
            rijAlg.KeySize = size;
            rijAlg.BlockSize = size;
            rijAlg.Key = keyBytes;
            rijAlg.IV = keyBytes;

            var encryptor = rijAlg.CreateEncryptor();
            byte[] plainText = Encoding.UTF8.GetBytes(originalText);
            // 암호화되어 bytes로 만들어진 데이터를 문자열로 변환.
            encryptedText = Convert.ToBase64String(encryptor.TransformFinalBlock(plainText, 0, plainText.Length));
        }
        return encryptedText;
    }

    private static string Decrypt(string encryptText, string key, int size)
    {
        if (!((128 == size) || (192 == size) || (256 == size))) throw new Exception("wrong size");
        if (string.IsNullOrEmpty(encryptText)) throw new ArgumentNullException("encryptText");
        if (string.IsNullOrEmpty(key)) throw new ArgumentNullException("key");

        string originalText = string.Empty;
        using (var rijAlg = new RijndaelManaged())
        {
            int byteSize = (int)(size * 0.125f);
            byte[] pwBytes = Encoding.UTF8.GetBytes(key);
            byte[] keyBytes = new byte[byteSize];

            var len = Math.Min(pwBytes.Length, keyBytes.Length);
            Array.Copy(pwBytes, keyBytes, len);

            rijAlg.Mode = CipherMode.CBC;
            rijAlg.Padding = PaddingMode.PKCS7;
            rijAlg.KeySize = size;
            rijAlg.BlockSize = size;
            rijAlg.Key = keyBytes;
            rijAlg.IV = keyBytes;

            byte[] encryptData = Convert.FromBase64String(encryptText);
            var decryptor = rijAlg.CreateDecryptor();
            originalText = Encoding.UTF8.GetString(decryptor.TransformFinalBlock(encryptData, 0, encryptData.Length));
        }
        return originalText;
    }
}
