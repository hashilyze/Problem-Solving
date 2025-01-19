// [Beakjoon] 2257. 화학식량

import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	public static void main(String[] args) throws IOException {
		String exp = br.readLine();
		
		// Solution
		Stack<Integer> stk = new Stack<Integer>();
		for(char ch: exp.toCharArray()) {
			if(ch == ')') { // 여는 괄호를 만날때까지 모두 더함
				int sum = 0;
				while(stk.peek() != '(') sum += stk.pop();
				stk.pop();
				stk.push(sum);
			} else if(Character.isDigit(ch)) { // 바로 앞의 값을 곱합
				stk.push(stk.pop() * (ch - '0'));
			} else { // '(' or 'H' or 'H' or 'O'
				stk.push(getValue(ch));
			}
		}
		int total = 0;
		while(!stk.isEmpty()) total += stk.pop();
		
		bw.append(total + "");
		bw.flush();
	}
	
	static int getValue(char ch) {
		if(ch == 'H') return 1;
		else if(ch == 'C') return 12;
		else if(ch == 'O') return 16;
		else return ch;
	}
	
}

