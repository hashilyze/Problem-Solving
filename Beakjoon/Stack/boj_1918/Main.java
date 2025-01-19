// [Beakjoon] 1918. 후위 표기식

import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	public static void main(String[] args) throws IOException {
		String exp = br.readLine();
		bw.append(solution(exp));
		bw.flush();
	}
	
	static String solution(String exp) {
		StringBuilder sb = new StringBuilder();
		Stack<Character> opStk = new Stack<Character>();
		
		for(char ch : exp.toCharArray()) {
			if(Character.isAlphabetic(ch)) {
				sb.append(ch);
			} else {
				switch(ch) {
				case '+':
				case '-':
				case '*':
				case '/':
					while(!opStk.isEmpty() && priority(opStk.peek()) <= priority(ch)) {
						sb.append(opStk.pop());
					}
					opStk.push(ch);
					break;
				case '(': 
					opStk.push(ch);
					break;
				case ')':
					while(opStk.peek() != '(') {
						sb.append(opStk.pop());
					}
					opStk.pop();
					break;
				}
			}
		}
		while(!opStk.isEmpty()) sb.append(opStk.pop());
		return sb.toString();
	}
	
	static int priority(char ch) {
		switch(ch) {
		case '*':
		case '/': 
			return 0;
		case '+':
		case '-': 
			return 1;
		default: 
			return 2;
		}
	}
}
