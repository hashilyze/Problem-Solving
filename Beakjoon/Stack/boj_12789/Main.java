// [Beakjoon] 12789. 도키도키 간식드리미

import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	public static void main(String[] args) throws IOException {
		int N = Integer.parseInt(br.readLine());
		String[] seq = br.readLine().split(" ");
		bw.append(solution(N, seq) ? "Nice" : "Sad");
		bw.flush();
	}
	
	static boolean solution(int N, String[] seq) {
		Deque<Integer> deq = new ArrayDeque<Integer>();	// A: 현재 줄서있는 곳
		for(String e : seq) {
			deq.addLast(Integer.parseInt(e));
		}
		
		Stack<Integer> stk = new Stack<Integer>(); // B: 한 명씩만 설 수 있는 공간 
		stk.push(N + 1);
		
		for(int next = 1; next <= N; ++next) {
			if(stk.peek() == next) {
				stk.pop();
			} else {
				while(deq.peekFirst() != next) {
					if(stk.peek() < deq.peekFirst()) {
						return false;
					}
					stk.push(deq.pollFirst());
				}
				deq.pollFirst();
			}
		}
		return true;
	}
}
