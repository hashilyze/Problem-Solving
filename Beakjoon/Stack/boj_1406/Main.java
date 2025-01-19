// [Beakjoon] 1406. 에디터

import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	public static void main(String[] args) throws IOException {
		Stack<Character> leftStack = new Stack<Character>();
		Stack<Character> rightStack = new Stack<Character>();
		for(char ch : br.readLine().toCharArray()) {
			leftStack.add(ch);
		}
		
		int N = Integer.parseInt(br.readLine());
		while(N-- > 0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			char cmd = st.nextToken().charAt(0);
			if(cmd == 'L') { // 커서를 왼쪽으로
				if(!leftStack.isEmpty()) {
					rightStack.push(leftStack.pop());
				}
			} else if(cmd == 'D') { // 커서를 오른쪽으로
				if(!rightStack.isEmpty()) {
					leftStack.push(rightStack.pop());
				}
			} else if(cmd == 'B') { // 왼쪽 문자 제거
				if(!leftStack.isEmpty()) {
					leftStack.pop();
				}
			} else if(cmd == 'P') { // 왼쪽에 문자 추가
				char ch = st.nextToken().charAt(0);
				leftStack.push(ch);
			}
		}
		
		StringBuffer sb = new StringBuffer();
		while(!rightStack.isEmpty()) leftStack.push(rightStack.pop());
		for(char ch : leftStack) sb.append(ch);
		bw.append(sb.toString());
		bw.flush();
	}
}
