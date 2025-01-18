// [Beakjoon] 11005. 진법 변환 2
// https://www.acmicpc.net/problem/11005

import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	public static void main(String[] args) throws IOException {
		// Input
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int B = Integer.parseInt(st.nextToken());
		
		// Solution
		StringBuilder sb = new StringBuilder();
		while(N > 0) {
			sb.append(toExtendedHexadecimal(N % B));
			N /= B;
		}
		sb.reverse();
		
		// Output
		bw.append(sb);
		bw.flush();
	}
	
	static char toExtendedHexadecimal(int digit) {
		if(digit < 10) return (char)(digit + '0');
		else return (char)(digit - 10 + 'A');
	}
}
