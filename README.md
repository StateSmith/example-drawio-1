# !NOTE! Slightly outdated 📅
Only [tutorial-2](https://github.com/StateSmith/tutorial-2) will be kept up to date with all the best practices and features. I only have so much time for documentation.

The diagram is still good though for experimentation.


<br/>
<br/>
<br/>

---


# Video Walk Through 🚶
https://youtu.be/qej8pXp3dX4

<br/>

# Cross Platform Example
Tested on Linux and Windows. Should work on mac as well.

This example uses new StateSmith features that are really helpful:
1. draw.io vscode plugin.
2. C# script files.

While you don't have to use StateSmith with vscode (you can go pure CLI),
it is really handy.

<br/>

# Install instructions 📦
Install `dotnet` and `dotnet-script` by following [this wiki page](https://github.com/StateSmith/StateSmith/wiki/StateSmith-install-requirements).

## draw.io (optional) 🖉
You'll also want to install the draw.io [vscode extension](https://marketplace.visualstudio.com/items?itemName=hediet.vscode-drawio).

## Intellisense (optional) 🔍
To get intellisense for our C# scripts, install the [official C# vscode extension](https://marketplace.visualstudio.com/items?itemName=ms-dotnettools.csharp).

You'll also need to run a few terminal commands for vscode to understand C# script files:

```
dotnet script init delete_me_dummy_file.csx
rm ./delete_me_dummy_file.csx
```

Then restart vscode and you should be good to go!

Full explanation and [details here.](https://github.com/StateSmith/StateSmith/wiki/Using-c%23-script-files-(.CSX)-instead-of-solutions-and-projects#setup-vscode-for-debugging-c-script-files-and-intellisense)

<br/>

# The Image is The Source!
One of the really cool features of draw.io is that the viewable svg file is also the design - as shown below! This is pretty excellent!

![](./src/Tutorial1Sm.drawio.svg)

The one downside though is that the editable draw.io xml is embedded as binary in the svg. This can be tricky if you have multiple developers changing the svg on different git branches and wanting to merge the changes together. This is a common problem with some other state machine software like Matlab Simulink. You could also choose to use regular XML `.drawio` files instead of `drawio.svg` files. This usually isn't an issue we run into at my work.

<br/>

# More info
* [Using C# script files](https://github.com/StateSmith/StateSmith/wiki/Using-c%23-script-files-(.CSX)-instead-of-solutions-and-projects)
* [Using draw.io](https://github.com/StateSmith/StateSmith/wiki/Getting-started-using-draw.io-with-StateSmith)
