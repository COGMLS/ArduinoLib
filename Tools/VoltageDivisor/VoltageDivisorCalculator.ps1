<################################################
 # Project: Voltage Divisor Calculator
 # ----------------------------------------------
 # Author: Matheus L. Silvati
 # -------------------------------
 # Version: 2.1.0
 # -------------------------------
 # PowerShell Compatibility: 3.0 (minimum)
 # -------------------------------
 # Notes: N/A
 # -------------------------------
 # OBS: N/A
################################################>

<#
.SYNOPSIS
    Calculate the Voltage Divisor
.DESCRIPTION
    Calculate the voltage divisor for analog array buttons and other usefull circuits, that need be readed by the microcontroller.
.NOTES
    This function is supported in Linux, if running on PowerShell 7.
.LINK
    No link available
.EXAMPLE
    VoltageDivCalc.ps1 -R0 100e3 -Vi = 4.96 -RN = (10e3, 25e3, 50e3, 75e3, 150e3, 300e3, 450e3, 600e3, 750e3, 900e3)
    
    Calculate the voltage divisor and the analog readings with R0 = 100kΩ, Vi = 4.96 V to resistors: 10k, 25kΩ, 50kΩ, 75kΩ, 150kΩ, 300kΩ, 450kΩ, 600kΩ, 750kΩ, 900kΩ.
.EXAMPLE
    VoltageDivCalc.ps1 -R0 100e3 -Vi = 4.96 -AN = (50, 100, 220, 330, 440, 530, 620, 750, 820, 900)
    
    Calculate the voltage divisor and the N resistors associated with R0 = 100kΩ, Vi = 4.96 V to get the analog read: 50, 100, 220, 330, 440, 530, 620, 750, 820, 900.
#>

Param
(
    # Reference Resistor or Main Resistor
    [Parameter(Position=0,Mandatory=$true)]
    [double]
    $R0,

    # Resistor(s) to divide the voltage
    [Parameter(Position=1,Mandatory=$false)]
    [double[]]
    $RN,

    # Analog read to make divisor resistor(s)
    [Parameter(Position=1,Mandatory=$false)]
    [double[]]
    $AN,

    # Input Voltage
    [Parameter(Position=2,Mandatory=$true)]
    [double]
    $Vi,

    # Bit precision for Unit Voltage reference. By default 10-bit is used.
    [Parameter(Position=3,Mandatory=$false)]
    [int]
    $BitPrecision = 10,
    
    # Voltage reference to calculate the Unit Voltage reference. By default 5.0 V is used.
    [Parameter(Position=4,Mandatory=$false)]
    [double]
    $Vref = 5.0,

    # Decimal Unit Voltage reference precision. By default use 4 decimals.
    [Parameter(Position=5,Mandatory=$false)]
    [int]
    $VrefPrecision = 4,

    # Use resistor prefix (y,z,a,f,p,n,u,m,c,d,da,h,k,M,G,T,P,E,Z,Y). Note: da - deca, expoent = 1. Note: If send no char/compatible char, will use as 'da'.
    [Parameter(Position=6,Mandatory=$false,DontShow=$true)]
    [char]
    $ResistorPrefix,

    # Use voltage prefix (y,z,a,f,p,n,u,m,c,d,da,h,k,M,G,T,P,E,Z,Y). Note: da - deca, expoent = 1. Note: If send no char/compatible char, will use as 'da'.
    [Parameter(Position=7,Mandatory=$false,DontShow=$true)]
    [char]
    $VoltagePrefix
)

[double]$UnitVref = [System.Math]::Round($Vref / ([System.Math]::Pow(2, $BitPrecision)), $VrefPrecision)

class VoltageDivisorClass
{
    [int]$ResistorIndex
    [double]$ResistorValue
    [double]$MainResistor
    [double]$VoltageIn
    [double]$VoltageOut
    [double]$AnalogRead
    [double]$UnitVoltageReference

    VoltageDivisorClass($RiIndex, $RValue, $MainR, $Vin, $UnitVref)
    {
        $this.ResistorIndex = $RiIndex
        $this.ResistorValue = $RValue
        $this.MainResistor = $MainR
        $this.VoltageIn = $Vin
        $this.UnitVoltageReference = $UnitVref

        $this.AnalogRead = -1.0
        $this.VoltageOut = -1.0
    }

    [void]Calculate()
    {
        $this.VoltageOut = ($this.ResistorValue / ($this.MainResistor + $this.ResistorValue)) * $this.VoltageIn
        $this.AnalogRead = ($this.VoltageOut / $this.UnitVoltageReference)
    }
}

class AnalogReadClass
{
    [int]$ResistorIndex
    [double]$ResistorValue
    [double]$MainResistor
    [double]$VoltageIn
    [double]$VoltageOut
    [double]$AnalogRead
    [double]$UnitVoltageReference

    AnalogReadClass($RiIndex, $ARead, $MainR, $Vin, $UnitVref)
    {
        $this.ResistorIndex = $RiIndex
        $this.AnalogRead = $ARead
        $this.MainResistor = $MainR
        $this.VoltageIn = $Vin
        $this.UnitVoltageReference = $UnitVref
        
        $this.ResistorValue = -1.0
        $this.VoltageOut = -1.0
    }

    [void]Calculate()
    {
        $this.VoltageOut = ($this.AnalogRead * $this.UnitVoltageReference)

        $this.ResistorValue = ($this.VoltageOut * $this.MainResistor) / ($this.VoltageIn - $this.VoltageOut)
    }
}

function MakeVoltageDivisors
{
    Param
    (
        [double]$MainR,
        [double]$Vin,
        [double]$UnitVref,
        [double[]]$RValues
    )

    [VoltageDivisorClass[]]$VDivisors = @()

    for ([int]$i = 0; $i -lt $RValues.Count; $i++)
    {
        $tmp = [VoltageDivisorClass]::new(($i + 1), $RValues[$i], $MainR, $Vin, $UnitVref)
        $tmp.Calculate()
        $VDivisors += $tmp
    }

    return $VDivisors
}

function MakeAnalogReaders
{
    Param
    (
        [double]$MainR,
        [double]$Vin,
        [double]$UnitVref,
        [double[]]$AnalogRead
    )

    [AnalogReadClass[]]$AReaders = @()

    for ([int]$i = 0; $i -lt $AnalogRead.Count; $i++)
    {
        $tmp = [AnalogReadClass]::new(($i + 1), $AnalogRead[$i], $MainR, $Vin, $UnitVref)
        $tmp.Calculate()
        $AReaders += $tmp
    }

    return $AReaders
}

if ($RN.Count -gt 0)
{
    $vd = MakeVoltageDivisors -MainR $R0 -Vin $Vi -UnitVref $UnitVref -RValues $RN
    
    $VoltageDivTableFields = 
        @{Label = "Index"; Expression = {$_.ResistorIndex}; Align = "Center"},
        @{Label = "Resistor (kΩ)"; Expression = {([System.Math]::Round($_.ResistorValue, 2) / 1e3).ToString("#")}; Align = "Center"},
        @{Label = "Voltage Out (V)"; Expression = {[System.Math]::Round($_.VoltageOut, 4)}; Align = "Center"},
        @{Label = "Analog Read"; Expression = {([System.Math]::Round($_.AnalogRead, 0).ToString("#"))}; Align = "Center"}
    
    Write-Output ($vd | Format-Table $VoltageDivTableFields)
}
elseif ($AN.Count -gt 0)
{
    $ar = MakeAnalogReaders -MainR $R0 -Vin $Vi -UnitVref $UnitVref -AnalogRead $AN
    
    $AnalogReadTableFields = 
        @{Label = "Index"; Expression = {$_.ResistorIndex}; Align = "Center"},
        @{Label = "Analog Read"; Expression = {([System.Math]::Round($_.AnalogRead, 0).ToString("#"))}; Align = "Center"},
        @{Label = "Resistor (kΩ)"; Expression = {([System.Math]::Round($_.ResistorValue, 2) / 1e3).ToString("#")}; Align = "Center"},
        @{Label = "Voltage Out (V)"; Expression = {[System.Math]::Round($_.VoltageOut, 4)}; Align = "Center"}
    
    Write-Output ($ar | Format-Table $AnalogReadTableFields)
}
else
{
    Write-Error -Exception "Unknown exception" -Message "An unidentified error was occured."
}