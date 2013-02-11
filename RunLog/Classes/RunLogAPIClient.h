#import "AFIncrementalStore.h"
#import "AFRestClient.h"

@interface RunLogAPIClient : AFRESTClient <AFIncrementalStoreHTTPClient>

+ (RunLogAPIClient *)sharedClient;

@end
