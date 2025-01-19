// [Beakjoon] 24511. queuestack

import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	public static void main(String[] args) throws IOException {
		// Inputs
		int N = Integer.parseInt(br.readLine());
		String[] types = br.readLine().split(" ");
		String[] queuestack = br.readLine().split(" ");
		int M = Integer.parseInt(br.readLine());
		String[] inputs = br.readLine().split(" ");
		
		// Solution
		int cnt = 0;
		for(int i = N - 1; i >= 0; --i) {
			if(types[i].equals("0")) { // queue
				bw.append(queuestack[i] + " ");
				if(++cnt == M) break;
			} else { } // stack
		}
		for(int i = 0; i < M; ++i) {
			if(cnt++ == M) break;
			bw.append(inputs[i] + " ");
		}
		
		// Output
		bw.flush();
	}
}
