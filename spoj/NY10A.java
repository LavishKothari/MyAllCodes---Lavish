import java.util.Scanner;

class NY10A {

    static int x=1;
    private static int get(String s)
    {
        switch (s){
            case "TTT": return 0;
            case "TTH": return 1;
            case "THT": return 2;
            case "THH": return 3;
            case "HTT": return 4;
            case "HTH": return 5;
            case "HHT": return 6;
            default: return 7;

        }
    }
    private static void solve(String s){
        int []arr=new int[8];
        for(int i=0;i<s.length()-2;i++){
            arr[get(s.substring(i,i+3))]++;
        }
        System.out.print(x+" ");x++;
        for(int i=0;i<8;i++)
            System.out.print(arr[i]+" ");
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t=sc.nextInt();
        while(t-->0)
        {
            int x = sc.nextInt();
            String s = sc.next();
            solve(s);
        }
    }
}
