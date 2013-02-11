## AFNetworking + AFIncrementalStore + SDScaffoldKit = SDScaffoldSync

![SDScaffoldKit with AFNetworking Template](http://f.cl.ly/items/102O2w052F3V0K3d3B1x/Screen%20Shot%202013-02-10%20at%207.09.11%20PM.png)

=======
## This Project Would Not Be Possible Without [Mattt Thompson](http://www.github.com/mattt). 
> SDScaffoldSync is a combination of [SDScaffoldKit](http://www.github.com/stevederico/sdscaffoldkit), [AFNetworking](https://github.com/AFNetworking/AFNetworking), and [AFIncrementalStore](https://github.com/AFNetworking/AFIncrementalStore) using the [Heroku-Core-Data-Buildback](https://github.com/mattt/heroku-buildpack-core-data). Without these contributions from [Mattt](http://www.github.com/mattt), none of this would be possible. I highly encourage everyone to follow & thank [Mattt Thompson](http://www.github.com/mattt) for his series of open source libraries covering the mission-critical aspects of an iOS app's infrastructure. Be sure to check out its sister projects: [GroundControl](https://github.com/mattt/GroundControl), [SkyLab](https://github.com/mattt/SkyLab), [CargoBay](https://github.com/mattt/CargoBay), and [houston](https://github.com/mattt/houston).

##**Create a Cloud Syncing Mobile App in 3 minutes**

Building an app that syncs its data in the cloud can be difficult. That's where `SDScaffoldSync` comes into play. `SDScaffoldSync` creates a REST endpoint (via [Heroku-Core-Data-Buildpack](https://github.com/mattt/heroku-buildpack-core-data)) and syncing code (via [AFIncremntalStore](https://github.com/AFNetworking/AFIncrementalStore)) for you. SDScaffoldSync also leverages SDScaffoldKit to give you ready-made views for your model objects. 

UIKit can be tedious and repeative to build simple CRUD interfaces. SDScaffoldSync is a simple library that provides Create, Read, Update, and Delete views out-of-the-box. Just create your Core Data model, hand it your Entity's name, a field to sort by, and BAM! You you have a cloud syncing app.

SDScaffoldSync is meant to save you time so you can focus on what matters, application logic. The library is still a little green behind the ears and I would love to see any issues or pull request you may have. There is a sample project if you have any question on how it all works.

Overall, this is a great way to get your project up and running then you can go from there.


## Getting Started
These are the exact steps needed to take to create an syncing client-server app in 3 minutes. You will need to have CocoaPods Installed on your machine.
Watch this video for a complete demo - 

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
