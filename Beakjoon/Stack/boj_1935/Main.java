// [Beakjoon] 1935. 후위 표기식2

import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
	public static void main(String[] args) throws IOException {
		int N = Integer.parseInt(br.readLine());
		String exp = br.readLine();
		int[] vars = new int[N];
		for(int i = 0; i < N; ++i) {
			vars[i] = Integer.parseInt(br.readLine());
		}
		
		System.out.printf("%.2f", solution(vars, exp));
	}
	
	static double solution(int[] vars, String exp) {
		Stack<Double> stk = new Stack<Double>();
		for(char ch : exp.toCharArray()) {
			if(Character.isAlphabetic(ch)) {
				stk.push((double)vars[ch - 'A']);
			} else {
				double rhs = stk.pop();
				double lhs = stk.pop();
				
				switch(ch) {
				case '+': stk.push(lhs + rhs); break;
				case '-': stk.push(lhs - rhs); break;
				case '*': stk.push(lhs * rhs); break;
				case '/': stk.push(lhs / rhs); break;
				}
				
			}
		}
		return stk.pop();
	}
}
