import re

import numpy as np
<<<<<<< HEAD
import uproot
=======
import ROOT
>>>>>>> 35a193aef6d55268338deed29107e660f57b89f8

# Load the data from the root file
data = uproot.open("data.root")["kin"].arrays(
    ["cosTheta_eta_hel_thrown", "phi_eta_hel_thrown", "Phi_thrown"], library="pd"
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
<<<<<<< HEAD
data = data.rename(
    {
        "cosTheta_eta_hel_thrown": "theta",
        "phi_eta_hel_thrown": "phi",
        "Phi_thrown": "Phi",
    },
    axis=1,
=======
data["theta"] = np.arccos(data.pop("cosTheta_eta_hel_thrown"))
data["phi"] = data.pop("phi_eta_hel_thrown")
data["Phi"] = data.pop("Phi_thrown") / (2 * np.pi)

# Convert the dictionary to a structured array
structured_array = np.empty(
    len(next(iter(data.values()))),
    dtype=[(key, data[key].dtype) for key in data.keys()],
>>>>>>> 35a193aef6d55268338deed29107e660f57b89f8
)

# Standardize the data to be angles in radians
DEGREE_TO_RADIAN = np.pi / 180.0
data["theta"] = np.arccos(data["theta"])
data["Phi"] = data["Phi"] * DEGREE_TO_RADIAN

data.to_csv("comparison.csv", index=False, sep=",")
