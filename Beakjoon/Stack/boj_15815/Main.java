// [Beakjoon] 15815. 천재 수학자 성필

import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	public static void main(String[] args) throws IOException {
		String exp = br.readLine();
		
		Stack<Integer> stk = new Stack<Integer>();
		for(char token : exp.toCharArray()) {
			if(Character.isDigit(token)) {
				stk.push(token - '0');
			} else {
				int rhs = stk.pop();
				int lhs = stk.pop();
				
				switch(token) {
				case '+': stk.push(lhs + rhs); break;
				case '-': stk.push(lhs - rhs); break;
				case '*': stk.push(lhs * rhs); break;
				case '/': stk.push(lhs / rhs); break;
				}
			}
		}
		bw.append(stk.pop().toString());
		bw.flush();
	}
}

