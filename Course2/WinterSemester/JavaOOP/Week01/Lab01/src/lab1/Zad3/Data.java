package lab1.Zad3;

public class Data {
    private final Integer originalData;
    private Integer data;

    public Data(Integer data) {
        setData(data);
        originalData = data;
    }

    public Integer getData() {
        return data;
    }

    public void setData(Integer data) {
        //Validating data
        if (data < 1000 || data > 9999)
            throw new IllegalArgumentException("Illegal data (must be 4 digits number): " + data);

        this.data = data;
    }

    public Integer getOriginalData() {
        return originalData;
    }

    public void encryptData() {
        if (data != originalData)
            return;
        Integer tempData = data;
        int[] modifiedData = new int[4];

        //Encrypting digits
        for (int i = 3; i >= 0; --i) {
            modifiedData[i] += ((tempData % 10 + 7) % 10);
            tempData /= 10;
        }

        shuffleDigits(modifiedData);

        data = convertToInteger(modifiedData);
    }

    public void decryptData() {
        if (data == originalData)
            return;
        Integer tempData = data;
        int[] modifiedData = new int[4];

        //Decrypting digits
        for (int i = 3; i >= 0; --i) {
            modifiedData[i] += (tempData % 10 + 3 /* +10 - 7 */) % 10;
            tempData /= 10;
        }

        shuffleDigits(modifiedData);

        data = convertToInteger(modifiedData);
    }

    private Integer convertToInteger(int[] modifiedData) {
        //Transforming array into integer
        Integer tempData = 0;
        for (int i = 0; i < 4; ++i) {
            tempData = tempData * 10 + modifiedData[i];
        }
        return tempData;
    }

    private void shuffleDigits(int[] modifiedData) {
        //Swapping first and third digit
        int temp = modifiedData[0];
        modifiedData[0] = modifiedData[2];
        modifiedData[2] = temp;

        //Swapping second and fourth digit
        temp = modifiedData[1];
        modifiedData[1] = modifiedData[3];
        modifiedData[3] = temp;
    }
}
