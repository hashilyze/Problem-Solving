// [Beakjoon] 2841. 외계인의 기타 연주

import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static final int STRING_NUM = 6;
	
	public static void main(String[] args) throws IOException {
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		//int P = Integer.parseInt(st.nextToken());
		
		List<Stack<Integer>> strings = new ArrayList<Stack<Integer>>(STRING_NUM);
		for(int i = 0; i < STRING_NUM; ++i) strings.add(new Stack<Integer>());
		for(int i = 0; i < STRING_NUM; ++i) strings.get(i).add(0);
		
		int cnt = 0;
		for(int i = 0; i < N; ++i) {
			st = new StringTokenizer(br.readLine());
			Stack<Integer> string = strings.get(Integer.parseInt(st.nextToken()) - 1);
			int fret = Integer.parseInt(st.nextToken());
			
			while(string.peek() > fret) { // 높은 프렛에서 손가락을 뗌
				string.pop();
				++cnt;
			}
			if(string.peek() != fret) { // 누르고 있지 않다면 프렛을 누름
				string.push(fret);
				++cnt;
			}
		}
		bw.append(cnt + "");
		bw.flush();
	}
}
