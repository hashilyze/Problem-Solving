// [Beakjoon] 4949. 균형잡힌 세상 

import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	public static void main(String[] args) throws IOException {
		while(true) {
			// Input
			String line = br.readLine();
			
			// Solution
			if(line.equals(".")) {
				break;
			}
			boolean ans = solution(line);
			
			// Output
			bw.append(ans ? "yes\n" : "no\n");
		}
		bw.flush();
	}
	
	static boolean solution(String str) {
		Stack<Character> stk = new Stack<Character>();
		stk.push('$'); // 빈 스택을 만들지 않기 위함
		
		for(char ch : str.toCharArray()) {
			if(ch == '(' || ch == '[') { 
				stk.push(ch);
			} else if(ch == ')') {
				if(stk.pop() != '(') return false;
			} else if(ch == ']') {
				if(stk.pop() != '[') return false;
			} else { } // 그 외: 무시
		}
		return stk.size() <= 1; // 닫는괄호가 부족한 지 확인
	}
}
