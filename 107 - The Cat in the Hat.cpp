#include <cstdio>
#include <cmath>
using namespace std;
typedef long long int llt;
int main()
{
 //   freopen ("input.txt","rt",stdin);
    int H,W;
    while (scanf("%d%d",&H,&W) != EOF){
        if (!H && !W) break;
        // klog(N+1) = logH
        // klogN = logW

        double C = log(H) / log(W);

        int L = 1, R = 2147483645, mid = (L + R)/2;
        while (L != R){
            if (log(mid+1) / log(mid) - C > 0.000000000001) L = mid+1;
            else if (log(mid+1) / log(mid) - C < -0.000000000001) R = mid;
            else break;
            mid = (L + R) / 2;
        }
        int N = mid;
        int k = round (log(H) / log(N+1));



        llt notWorking = 0;
        llt totalHeight = 0;
        W = 1;
        for (int i = 0; i < k; i++){
            notWorking += W;
            totalHeight += (H * W);
            W *= N;
            H /= (N+1);
        }
        printf("%lld %lld\n",notWorking, totalHeight+(H * W));
    }
    return 0;
}
