## What is an architecture decision record?

An **architecture decision record** (ADR) is a document that captures an important architectural decision made along with its context and consequences.

An **architecture decision** (AD) is a software design choice that addresses a significant requirement.

An **architecture decision log** (ADL) is the collection of all ADRs created and maintained for a particular project (or organization).

An **architecturally-significant requirement** (ASR) is a requirement that has a measurable effect on a software system’s architecture.

All these are within the topic of **architecture knowledge management** (AKM).

The goal of this document is to provide a fast overview of ADRs, how to create them, and where to look for more information.

Abbreviations:

  * **AD**: architecture decision

  * **ADL**: architecture decision log

  * **ADR**: architecture decision record

  * **AKM**: architecture knowledge management

  * **ASR**: architecturally-significant requirement



## Suggestions for writing good ADRs

Characteristics of a good ADR:

  * Point in Time - Identify when the AD was made

  * Rationality - Explain the reason for making the particular AD

  * Immutable record - The decisions made in a previously published ADR should not be altered

  * Specificity - Each ADR should be about a single AD

Characteristics of a good "Context" section in an ADR:

  * Explain your organization's situation and business priorities

  * Include rationale and considerations based on social and skills makeups of your teams

Characteristics of good "Consequences" section in an ADR:

  * Right approach - "We need to start doing X instead of Y"

  * Wrong approach - Do not explain the AD in terms of "Pros" and "Cons" of having made the particular AD

A new ADR may take the place of a previous ADR:

  * When an AD is made that replaces or invalidates a previous ADR, a new ADR should be created
