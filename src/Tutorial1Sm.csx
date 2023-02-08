#!/usr/bin/env dotnet-script
// This is a c# script file

#r "nuget: StateSmith, 0.7.11-alpha" // this line specifies which version of StateSmith to use and download from c# nuget web service.

// spell-checker: ignore drawio

using StateSmith.Input.Expansions;
using StateSmith.Output.UserConfig;
using StateSmith.Runner;

SmRunner runner = new(diagramPath: "Tutorial1Sm.drawio.svg", new MyGlueLogic());
runner.Run();

// ignore C# guidelines for script stuff below
#pragma warning disable IDE1006, CA1050 

/// <summary>
/// This class gives StateSmith the info it needs to generate working C code.
/// It adds user code to the generated .c/.h files, declares user variables,
/// and provides diagram code expansions. This class can have any name.
/// </summary>
public class MyGlueLogic : IRenderConfigC
{
    // You can define RenderConfig options in the diagram now if you like.
    // See https://github.com/StateSmith/StateSmith/issues/23
    string IRenderConfigC.HFileIncludes => @"
        // user IRenderConfigC.HFileIncludes: whatever you want to put in here.
    ";

    /// <summary>
    /// This nested class creates expansions because it is inside a class that implements `IRenderConfigC`.
    /// This class can have any name.
    /// </summary>
    public class MyExpansions : UserExpansionScriptBase
    {
        public string boom3() => "light_boom3()";
    }
}
