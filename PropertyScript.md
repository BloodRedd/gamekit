


# Introduction #
Property script is a structured property file loader. It's very similar to Ogre scripts.
It contains recursive or nested nodes, with key value pairs allowed in each node. Custom
rules and types are defined within the parser using the script interface, making it generic enough to be used
for multiple purposes.



## Grammar Rules ##
```
comment: 
	{ }
|
	'/' '*' ... '*' '/' {}
|
	'/' '/' ... '\n' {}

Node: 
	{ }
|
	name '{' Node '}' {}
|
	type name '{' Node '}' {}
|
	type name ':' extends '{' Node '}' {}
|
	KeyValue {}

KeyValue: 
	{ }
|
	key '=' value ';' {}
| 
	key = '=' Node '.' key ';' {}

```


# BFont (.bfont) #


This is an internal Blender VFont to Ogre Font converter. It's purpose is
to extract internal .ttf files that are packed inside blend files and make them
usable for Ogre overlay scripts.
The .bfont script is accessed through Blender's Text editor.


## Syntax ##
```

// Declaration 

NameExposedToOgreOverlays
{
	source       = Blender VFont id name;
	size         = Truetype size;
	resolution   = Truetype resolution;
}

// Example usage

BigFont
{
	source       = DejaVuSans;
	size         = 72;
	resolution   = 72;
}

SmallFont
{
	source       = DejaVuSans;
	size         = 12;
	resolution   = 32;
}

```