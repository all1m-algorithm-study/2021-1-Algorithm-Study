import java.io.*;
class Main{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    
    public static void main(String[] args) throws IOException{
        long k = Long.parseLong(br.readLine())-1;
        int cnt=0;
        while(k>0){
            if((k&1) ==1) cnt++;
            k>>=1;
        }
        System.out.println((cnt%2==0)?0:1);
    }
}