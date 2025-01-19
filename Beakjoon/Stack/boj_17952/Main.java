// [Beakjoon] 17952. 과제는 끝나지 않아!

import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	public static void main(String[] args) throws IOException {
		int N = Integer.parseInt(br.readLine());
		
		int total = 0;
		Stack<Entry> stk = new Stack<Main.Entry>();
		while(N-- > 0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			if(st.nextToken().equals("1")) {
				int score = Integer.parseInt(st.nextToken());
				int left = Integer.parseInt(st.nextToken());
				stk.push(new Entry(score, left));
			}
			
			if(!stk.isEmpty()) {
				if(--stk.peek().left == 0) {
					total += stk.pop().score;
				}
			}
		}
		
		
		bw.append(total + "");
		bw.flush();
	}
	
	static class Entry{
		public Entry() { };
		public Entry(int score, int left) {
			this.score = score;
			this.left = left;
		};
		
		public int score = 0;
		public int left = 0;
	}
}

