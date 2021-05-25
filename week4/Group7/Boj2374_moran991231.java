import java.io.*;
class Main{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int N;
    static int[] A;
    static long count=0;
    public static int stoi(String s){
        return Integer.parseInt(s);
    }

    public static long getMax(int s, int e){
        if(s==e) // s==max_i==e
            return A[s];
        if(s+1==e){
            int temp = Math.abs(A[s]-A[e]);
            count +=temp;
            return Math.max(A[s],A[e]);
        }

        //find idx of max value
        int max=A[s], max_i =s;
        for(int i=s; i<=e; i++){
            if(A[i]>max){
                max=A[i];
                max_i  =i;
            }
        }
        int temp=0;
        // separate left/right
        if(s==max_i)
        	temp += (max-getMax(max_i+1,e));
        else if(e == max_i){
        	temp += (max-getMax(s,max_i-1));
        }
        else {
        	temp += (max-getMax(s,max_i-1));
        	temp += (max-getMax(max_i+1,e));
        }
        count +=temp;
        return max;
    }

    public static void main(String[] args) throws IOException{
        N = stoi(br.readLine());
        A = new int[N];
        count=0;
        for(int i=0; i<N;i++)
            A[i] = stoi(br.readLine());
        getMax(0,N-1);
        System.out.println(count);
        

    }
}
