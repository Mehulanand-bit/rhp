import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int K = sc.nextInt();

        for(int wid = 1; wid <= K; wid++){
            Worker w = new Worker(wid);
            w.doWork(N);
        }

      
    }
}
