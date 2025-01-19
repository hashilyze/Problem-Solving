// [Beakjoon] 5397. 키로거 

import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	public static void main(String[] args) throws IOException {
		int N = Integer.parseInt(br.readLine());
		while(N-- > 0) {
			String log = br.readLine();
			bw.append(solution(log)).append('\n');
		}
		bw.flush();
	}
	
	static String solution(String log) {
		LinkedList<Character> li = new LinkedList<Character>();
		ListIterator<Character> it = li.listIterator();
		
		for(char ch : log.toCharArray()) {
			switch(ch){
			case '<': // 커서를 왼쪽으로 이동
				if(it.hasPrevious()) it.previous();
				break;
			case '>': // 커서를 오른쪽으로 이동
				if(it.hasNext()) it.next();
				break;
			case '-': // 커서의 왼쪽 글자를 지움
				if(it.hasPrevious()) {
					it.previous();
					it.remove();
				}
				break;
			default:
				it.add(ch);
				break;
			}
		}
		
		StringBuilder sb = new StringBuilder(li.size());
		for(char ch : li) sb.append(ch);
		return sb.toString();
		
	}
}
