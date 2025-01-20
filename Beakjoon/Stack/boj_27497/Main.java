// [Beakjoon] 27497. 알파벳 블록

import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	public static void main(String[] args) throws IOException {
		int N = Integer.parseInt(br.readLine());
		
		Stack<Integer> stk = new Stack<Integer>();
		Deque<Character> deq = new ArrayDeque<Character>();
		while(N-- > 0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int cmd = Integer.parseInt(st.nextToken());
			if(cmd == 3) {
				if(deq.isEmpty()) continue;
				
				if(stk.pop() < 0) deq.removeFirst(); 
				else deq.removeLast();
			} else {
				char ch = st.nextToken().charAt(0);
				if(cmd == 1) {
					deq.addLast(ch);	// 맨 뒤에 추가
					stk.push(1);
				} else { // cmd == 2
					deq.addFirst(ch); 	// 맨 앞에 추가
					stk.push(-1);
				}
			}
		}
		
		// Output
		for(char ch : deq) bw.append(ch);
		if(deq.isEmpty()) bw.append('0');
		bw.flush();
	}
}

