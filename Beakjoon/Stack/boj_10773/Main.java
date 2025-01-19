// [Beakjoon] 10773. 제로
// https://www.acmicpc.net/problem/10773

import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	public static void main(String[] args) throws IOException {
		// Input
		int K = Integer.parseInt(br.readLine());
		
		// Solution
		Stack<Integer> stk = new Stack<Integer>();
		while(K-- > 0){
			int n = Integer.parseInt(br.readLine());
			if(n != 0) stk.add(n);
			else stk.pop();
		}
		
		long sum = 0L;
		for(int e : stk) {
			sum += e;
		}
		
		// Output
		bw.append("" + sum);
		bw.flush();
	}
}
