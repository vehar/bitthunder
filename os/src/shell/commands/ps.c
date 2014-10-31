#include <bitthunder.h>
#include <stdlib.h>
#include <string.h>

struct process_time {
	BT_u64 ullRuntimeCounter;
};

static int bt_ps(BT_HANDLE hShell, int argc, char **argv) {

	BT_HANDLE hStdout = BT_ShellGetStdout(hShell);
	BT_u32 i = 0;
	struct bt_process_time oTime;

	BT_u32 total_processes = BT_GetTotalProcesses();

	struct process_time *runtimes = BT_kMalloc(sizeof(struct process_time) * total_processes);
	if(!runtimes) {
		return -1;
	}

	BT_u64 runtime = BT_GetGlobalTimer();
	for(i = 0; i < total_processes; i++) {
		BT_GetProcessTime(&oTime, i);
		runtimes[i].ullRuntimeCounter = oTime.ullRunTimeCounter;
	}

	BT_ThreadSleep(1000);

	runtime = BT_GetGlobalTimer() - runtime;
	for(i = 0; i < total_processes; i++) {
		BT_GetProcessTime(&oTime, i);
		runtimes[i].ullRuntimeCounter = oTime.ullRunTimeCounter - runtimes[i].ullRuntimeCounter;
	}

	bt_fprintf(hStdout, "PID   Name                              CPU    Threads\n");

	char *pBuf = BT_kMalloc(128);
	if (pBuf) {
		float fTotal = 0;
		BT_u32 nTotal = 0;
		for(i = 0; i < total_processes; i++) {
			BT_GetProcessTime(&oTime, i);
			float fPercentage = ((float)runtimes[i].ullRuntimeCounter / ((float)runtime / 100));
			BT_u32 ulLen = sprintf(pBuf, "%-6d%-31s%5.1f%%", oTime.ulPID, oTime.name, fPercentage);
			ulLen += sprintf(pBuf+ulLen, "%11d\n", oTime.ulthreads);
			bt_fprintf(hStdout, pBuf);
			fTotal += fPercentage;
			nTotal += oTime.ulthreads;
		}
		sprintf(pBuf, "      TOTAL                          %5.1f%%%11d\n", fTotal, nTotal);
		bt_fprintf(hStdout, pBuf);
		BT_kFree(pBuf);
	}

	bt_fprintf(hStdout, "Total runtime %d seconds\n", (BT_u32) (BT_GetGlobalTimer() / (BT_u64)BT_GetGlobalTimerRate()));

	BT_kFree(runtimes);

	return 0;
}


BT_SHELL_COMMAND_DEF oCommand = {
	.szpName = "ps",
	.pfnCommand = bt_ps,
};
