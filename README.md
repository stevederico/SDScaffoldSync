## AFNetworking + AFIncrementalStore + SDScaffoldKit = Client/Server App

![SDScaffoldKit with AFNetworking Template](http://f.cl.ly/items/102O2w052F3V0K3d3B1x/Screen%20Shot%202013-02-10%20at%207.09.11%20PM.png)

These are the exact steps needed to take to create an syncing client-server app in 3 minutes. Watch this video for a complete demo. You will need to have CocoaPods Installed on your machine.

1. Install [CocoaPods](http://cocoapods.org)
2. Create New Project with [AFNetworking Xcode Template](https://github.com/stevederico/Xcode-Project-Templates)
2. Close current project. `cd` to `PROJECTNAME` directory then 
3. Run `pod install`
3. Run `open PROJECTNAME.xcworkspace`
4. Create `ENTITYNAME` in `PROJECTNAME.xcdatamodeld` file
5. Run `git commit -a -m "first commit"`
5. Run `heroku create --buildpack git://github.com/mattt/heroku-buildpack-core-data.git`
6. Run `git push heroku master`
7. Copy random-name-here.herokuapp.com url from terminal, set `kAPIBaseURLString` in `PROJECTNAMEAPIClient.m` to random-name-here.herokuapp.com url.
8. Add [SDScaffoldKit](http://www.github.com/stevederico/SDScaffoldkit) to project. Then add `#import "SDScaffoldKit.h"` to `PROJECTNAME-Prefix.pch`
9. Create `SDScaffoldIndexViewController` instance and set it to the `rootViewController` of the main `navigationController`.
10. App Delegate should look like this:
```objective-c
- (BOOL)application:(UIApplication *)applicationdidFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    NSURLCache *URLCache = [[NSURLCache alloc] initWithMemoryCapacity:8 * 1024 * 1024 diskCapacity:20 * 1024 * 1024 diskPath:nil];
    [NSURLCache setSharedURLCache:URLCache];
    
    [[AFNetworkActivityIndicatorManager sharedManager] setEnabled:YES];
    
    SDScaffoldIndexViewController *scaffoldViewController = [[SDScaffoldIndexViewController alloc] 
    initWithEntityName:@"ENTITYNAME" sortBy:@"PROPERTY" context:self.managedObjectContext];
    
    self.navigationController = [[UINavigationController alloc] initWithRootViewController:scaffoldViewController];
    
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    self.window.rootViewController = self.navigationController;
    [self.window makeKeyAndVisible];
    
    return YES;
}
```
10. open http://kAPIBaseURLString/MODELNAMEs in your browser i.e. [http://sleepy-eyrie-2619.herokuapp.com/runs](http://sleepy-eyrie-2619.herokuapp.com/runs)
11. Run Xcode applciation
12. Follow [@stevederico](http://www.twitter.com) on twitter, tell me what you think. Thank [@mattt](http://www.twitter.com/stevederico) for the wonderful AFNetworking & AFIncrementalStore.

Common Errors
* Don't forget to change the build target from Pods. Click Pods next to the Stop button and change to PROJECTNAME, then build and Run.
![Bad](http://f.cl.ly/items/1t18043V3x2p2g1K1e2o/Screen%20Shot%202013-02-10%20at%204.13.50%20PM.png)
![Good]( http://f.cl.ly/items/29060u3d1j2x323w3z2w/Screen%20Shot%202013-02-10%20at%204.13.59%20PM.png)

LEGEND
* PROJECTNAME - Full name of the Project i.e. "RunnerLog"
* ENTITYNAME - Core Data Model Entity Name i.e. "Run"
* PROPERTY - An attribute of the new Entity i.e "summary"
* random-name-here.herokuapp.com url - Heroku webserver url i.e. http://sleepy-eyrie-2619.herokuapp.com
