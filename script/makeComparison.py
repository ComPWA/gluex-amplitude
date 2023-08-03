import ROOT
import re
import numpy as np

# Load the root tree
data = ROOT.RDataFrame("kin", "data.root").AsNumpy(
    ["cosTheta_eta_hel_thrown", "phi_eta_hel_thrown", "Phi_thrown"]
)

# Load the intensities extracted by print_amplitudes.cc
intensities = []
with open(".print_amplitudes.log", "r") as file:
    for line in file:
        if "INTENSITY =" in line:
            line = re.sub(" +", " ", line.rstrip().lstrip())
            intensities.append(float(line.split()[2]))
intensities = np.array(intensities)

assert len(intensities) == len(data["cosTheta_eta_hel_thrown"])

# Rename dictionary keys
data["intensity"] = intensities
data["theta"] = np.arccos(data.pop("cosTheta_eta_hel_thrown"))
data["phi"] = data.pop("phi_eta_hel_thrown")
data["Phi"] = data.pop("Phi_thrown")/(2*np.pi)

# Convert the dictionary to a structured array
structured_array = np.empty(
    len(next(iter(data.values()))),
    dtype=[(key, data[key].dtype) for key in data.keys()],
)
for key in data.keys():
    structured_array[key] = data[key]

# Save the structured array to a CSV file
np.savetxt(
    "comparison.csv",
    structured_array,
    delimiter=",",
    fmt="%s",
    header=",".join(data.keys()),
    comments="",
)
