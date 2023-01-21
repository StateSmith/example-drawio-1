#!/usr/bin/env dotnet-script
// This is a c# script file

#r "nuget: StateSmith, 0.7.4-alpha" // this line specifies which version of StateSmith to use and download from c# nuget web service.

using StateSmith.Input.Expansions;
using StateSmith.output;
using StateSmith.output.C99BalancedCoder1;
using StateSmith.output.UserConfig;
using StateSmith.Runner;
using System;
using System.Runtime.InteropServices;


////////////// START OF C# SCRIPT PROGRAM /////////////
var projectDir = GetThisDir() + "/../";
var srcDirectory = GetThisDir() + "/";
var diagramFile = $"{srcDirectory}Tutorial1Sm.drawio.svg";

MyGlueFile myGlueFile = new();
RunnerSettings settings = new(myGlueFile, diagramFile: diagramFile, outputDirectory: srcDirectory);
settings.filePathPrintBase = projectDir; // used for pretty printing paths
SmRunner runner = new(settings);
runner.Run();

MaybeWaitForKeyPress(); // feel free to remove
////////////// END OF C# SCRIPT /////////////



////////////// classes and functions follow /////////////


// see https://stackoverflow.com/questions/46728845/c-sharp-for-scripting-csx-location-of-script-file
string GetThisDir([System.Runtime.CompilerServices.CallerFilePath] string fileName = null)
{
    return Path.GetDirectoryName(fileName);
}

// Waiting for a key press can be handy if this script was launched by double clicking.
// This will give you a chance to see result before the console window closes.
// Feel free to remove.
static void MaybeWaitForKeyPress()
{
    if (!Debugger.IsAttached && !Console.IsInputRedirected && RuntimeInformation.IsOSPlatform(OSPlatform.Windows))
    {
        Console.WriteLine("Press any key to finish");
        Console.ReadKey(); // only do if not debugging because vscode debugging will throw at this line
    }
}

/// <summary>
/// This class gives StateSmith the info it needs to generate working C code.
/// It adds user code to the generated .c/.h files, declares user variables,
/// and provides diagram code expansions.
/// </summary>
public class MyGlueFile : IRenderConfigC
{
    // Anything you type in the below string ends up in the generated h file
    string IRenderConfigC.HFileIncludes => StringUtils.DeIndentTrim(@"
        // Some user .h file comment...
    ");

    // Anything you type in the below string ends up in the generated c file
    string IRenderConfigC.CFileIncludes => StringUtils.DeIndentTrim(@"
        // Some user .c file comment...
        #include ""light.h""
    ");

    // Anything you type in the below string ends up in the state machine user variables section.
    // If the string is blank, then no user variables section is created.
    string IRenderConfigC.VariableDeclarations => StringUtils.DeIndentTrim(@"
        uint8_t count;  // some user description for count field
    ");

    /// <summary>
    /// This nested class creates expansions because it is inside MyGlueFile.
    /// </summary>
    public class Expansions : UserExpansionScriptBase
    {
        #pragma warning disable IDE1006 // Naming Styles
        #pragma warning restore IDE1006 // Naming Styles
    }
}


